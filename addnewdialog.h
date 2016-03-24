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
 * File:   addnewdialog.h
 * Author: Eric Jasinski
 * Company: AE3
 *
 * Created on 24.03.2016
 */



#ifndef ADDNEWDIALOG_H
#define ADDNEWDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewDialog;
}

class AddNewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewDialog(QWidget *parent = 0);
    ~AddNewDialog();

private slots:
    void on_AddButton_clicked();

private:
    Ui::AddNewDialog *ui;
};

#endif // ADDNEWDIALOG_H
