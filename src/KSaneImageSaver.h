/* ============================================================
* Date        : 2010-07-02
* Description : Image saver class for libksane image data.
*
* Copyright (C) 2010 by Kare Sars <kare dot sars at iki dot fi>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License or (at your option) version 3 or any later version
* accepted by the membership of KDE e.V. (or its successor approved
*  by the membership of KDE e.V.), which shall act as a proxy
* defined in Section 14 of version 3 of the license.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License.
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*
* ============================================================ */

#ifndef KSANE_IMAGE_SAVER_H
#define KSANE_IMAGE_SAVER_H

#include <libksane/ksane.h>

#include <QThread>

class KSaneImageSaver : public QThread
{
    Q_OBJECT
    public:
        KSaneImageSaver(QObject *parent = 0);
        ~KSaneImageSaver();

        bool savePng(const QString &name, const QByteArray &data, int width, int height, int format);

        bool savePngSync(const QString &name, const QByteArray &data, int width, int height, int format);

        bool saveTiff(const QString &name, const QByteArray &data, int width, int height, int format);

        bool saveTiffSync(const QString &name, const QByteArray &data, int width, int height, int format);

    Q_SIGNALS:
        void imageSaved(bool success);
        
    protected:
        void run();

    private:
        struct Private;
        Private * const d;

};

#endif


