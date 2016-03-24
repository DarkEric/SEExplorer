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
 * File:   addnewdialog.cpp
 * Author: Eric Jasinski
 * Company: AE3
 *
 * Created on 24.03.2016
 */



#include "addnewdialog.h"
#include "ui_addnewdialog.h"
#include "qdatabase.h"

AddNewDialog::AddNewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDialog)
{
    ui->setupUi(this);
}

AddNewDialog::~AddNewDialog()
{
    delete ui;
}

void AddNewDialog::on_AddButton_clicked()
{
    QDataBase* dbase = QDataBase::getInstance();
    dbase->addNewData(ui->nameLineEdit->text(),ui->countLineEdit->text().toInt());
    close();
}
