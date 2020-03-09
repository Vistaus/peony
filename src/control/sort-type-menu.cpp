/*
 * Peony-Qt
 *
 * Copyright (C) 2020, Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Authors: Yue Lan <lanyue@kylinos.cn>
 *
 */

#include "sort-type-menu.h"

SortTypeMenu::SortTypeMenu(QWidget *parent) : QMenu(parent)
{
    auto sortTypeGroup = new QActionGroup(this);
    m_sort_types = sortTypeGroup;
    sortTypeGroup->setExclusive(true);

    auto fileName = addAction(tr("File Name"));
    fileName->setCheckable(true);
    sortTypeGroup->addAction(fileName);

    auto fileSize = addAction(tr("File Size"));
    fileSize->setCheckable(true);
    sortTypeGroup->addAction(fileSize);

    auto fileType = addAction(tr("File Type"));
    fileType->setCheckable(true);
    sortTypeGroup->addAction(fileType);

    auto modifiedDate = addAction(tr("Modified Data"));
    modifiedDate->setCheckable(true);
    sortTypeGroup->addAction(modifiedDate);

    auto fileLabel = addAction(tr("File Label"));
    fileLabel->setCheckable(true);
    sortTypeGroup->addAction(fileLabel);

    connect(sortTypeGroup, &QActionGroup::triggered, this, [=](QAction *action){
        int index = sortTypeGroup->actions().indexOf(action);
        switchSortTypeRequest(index);
    });

    addSeparator();

    auto sortOrderGroup = new QActionGroup(this);
    m_sort_orders = sortOrderGroup;
    sortOrderGroup->setExclusive(true);

    auto ascending = addAction(tr("Ascending"));
    ascending->setCheckable(true);
    sortOrderGroup->addAction(ascending);

    auto descending = addAction(tr("Descending"));
    descending->setCheckable(true);
    sortOrderGroup->addAction(descending);

    connect(sortTypeGroup, &QActionGroup::triggered, this, [=](QAction *action){
        int index = sortTypeGroup->actions().indexOf(action);
        switchSortOrderRequest(Qt::SortOrder(index));
    });
}

void SortTypeMenu::setSortType(int type)
{
    if (m_sort_type != type) {
        m_sort_type = type;
        m_sort_types->triggered(m_sort_types->actions().at(type));
    }
}

void SortTypeMenu::setSortOrder(Qt::SortOrder order)
{
    if (m_sort_order != order) {
        m_sort_order = order;
        m_sort_orders->triggered(m_sort_orders->actions().at(order));
    }
}
