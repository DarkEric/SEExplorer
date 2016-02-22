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
#include "QDebug"

QDataBase* QDataBase::pInstance = NULL;

QDataBase::QDataBase(QObject *parent) : QObject(parent)
{
    dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("SEExplorerDB.sqlite");
    if (!dbase.open()) {
        qDebug() << "Error open DataBase";
    }
}

QDataBase* QDataBase::getInstance(QObject *parent)
{
    if(!pInstance)
    {
        pInstance = new QDataBase(parent);
        qDebug()<<"getInstance(): Create QDataBase()\n";
    }
    qDebug()<<"getInstance(): Return"<<pInstance<<"\n";
    return pInstance;
}

QDataBase::~QDataBase()
{
    qDebug()<<"Destructor QDataBase()";
}
