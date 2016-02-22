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
 * File:   qdatabase.h
 * Author: Eric Jasinski
 * Company: AE3
 *
 * Created on 22.02.2016
 */



#ifndef QDATABASE_H
#define QDATABASE_H

#include <QObject>
#include <QSqlDatabase>

class QDataBase : public QObject
{
    Q_OBJECT
public:
    static QDataBase* getInstance(QObject *parent=0);
private:
    static QDataBase* pInstance;
    explicit QDataBase(QObject *parent = 0);
    explicit QDataBase(const QDataBase&);
    QDataBase* operator=(QDataBase);
    ~QDataBase();

    QSqlDatabase dbase;

signals:

public slots:

};

#endif // QDATABASE_H
