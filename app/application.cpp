/*
  Copyright (C) 2008-2009 by Eike Hein <hein@kde.org>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of
  the License or (at your option) version 3 or any later version
  accepted by the membership of KDE e.V. (or its successor appro-
  ved by the membership of KDE e.V.), which shall act as a proxy
  defined in Section 14 of version 3 of the license.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see http://www.gnu.org/licenses/.
*/


#include "application.h"
#include "mainwindow.h"


bool Application::m_isKDE46OrHigher = false;

Application::Application() : KUniqueApplication()
{
    m_mainWindow = 0;

    if (KDE::version() >= KDE_MAKE_VERSION(4, 6, 0))
        m_isKDE46OrHigher = true;
}

Application::~Application()
{
}

int Application::newInstance()
{
    if (!m_mainWindow)
    {
        m_mainWindow = new MainWindow();

        m_mainWindow->hide();
    }
    else
        m_mainWindow->toggleWindowState();

    return 0;
}
