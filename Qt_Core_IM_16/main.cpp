#include <QtCore/QCoreApplication>

#include <qstorageinfo.h>
#include <qfileinfo.h>
#include <qdir.h>
#include <qdebug.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	foreach(QStorageInfo storage, QStorageInfo::mountedVolumes()) {
		qInfo() << "Name: " << storage.displayName();
		qInfo() << "Type: " << storage.fileSystemType();
		qInfo() << "Total: " << storage.bytesTotal()/1000/1000 << "MB";
		qInfo() << "Available: " << storage.bytesAvailable() / 1000 / 1000 << "MB";
		qInfo() << "Device: " << storage.device();
		qInfo() << "Root: " << storage.isRoot();
		qInfo("");
	}

	QStorageInfo root = QStorageInfo::root();
	QDir dir(root.rootPath());

	foreach(QFileInfo fi, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
		qInfo() << fi.filePath();
	}

	return a.exec();
}
