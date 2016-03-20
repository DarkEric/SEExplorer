/*
 *  This file is part of SEExplorer.
 *
 *  SEExplorer is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SEExplorer is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SEExplorer.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * File:   mainwindow.cpp
 * Author: Eric Jasinski
 * Company: AE3
 *
 * Created on 22.02.2016
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdatabase.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFilmListTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::setFilmListTable()
{
    QDataBase* dbase = QDataBase::getInstance(this);
    ui->FilmListTable->setModel(dbase->getTable());
    return true;
}
