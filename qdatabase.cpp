/*
 *  This file is part of PROJECTNAME.
 *
 *  PROJECTNAME is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PROJECTNAME is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with PROJECTNAME.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * File:   qdatabase.cpp
 * Author: Eric Jasinski
 * Company: AE3
 *
 * Created on 22.02.2016
 */



#include "qdatabase.h"
#include <QDebug>
#include <QSqlError>
#include <QFile>
#include <QSqlTableModel>

QDataBase* QDataBase::pInstance = NULL;

QDataBase::QDataBase(QObject *parent) : QObject(parent)
{
    if(!QFile::exists("SEExplorerDB.sqlite"))
    {
        createDataBase();
        createTables();
    }
    else
    {
        connectDataBase();
    }

}

QDataBase* QDataBase::getInstance(QObject *parent)
{
    if(!pInstance)
    {
        pInstance = new QDataBase(parent);
    }
    return pInstance;
}

QDataBase::~QDataBase()
{
    qDebug()<<"Destructor QDataBase()";
}

bool QDataBase::connectDataBase()
{
    dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("SEExplorerDB.sqlite");
    if (!dbase.open()) {
        emit QDataBaseError(dbase.lastError().text());
        return false;
    }
    return true;
}

bool QDataBase::createDataBase()
{
    if(!connectDataBase())
    {
        return false;
    }
    return true;
}

bool QDataBase::sendingRequest(QString& str)
{
    QSqlQuery query;
    if (!query.exec(str)){
        emit QDataBaseError(query.lastError().text());
        return false;
    }
    return true;
}

bool QDataBase::createTables()
{
    QString str = "CREATE TABLE FilmList ("
            "id integer PRIMARY KEY NOT NULL, "
            "name VARCHAR(255), "
            "numberSeries integer, "
            "currentSeries integer DEFAULT 1"
            ");";
    return sendingRequest(str);
}

bool QDataBase::addNewData(QString &name, int number)
{
    QString str = "INSERT INTO FilmList "
                  "(name,numberSeries) "
                  "VALUES ('"+name+"', "
                           +QString::number(number)+");";
    return sendingRequest(str);
}

QAbstractTableModel* QDataBase::getTable()
{
    QSqlTableModel* model = new QSqlTableModel(this,dbase);
    model->setTable("FilmList");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    return model;
}
