// #include "ascommunicator.h"

// #include <QFile>
// #include <QTextStream>
// #include <QDebug>
// #include <QDir>



// void ASCommunicator::init()
// {
//     checkAndCreateFile("QtRequestType.txt")
//     checkAndCreateFile("QtRequest.txt")
// }

// void ASCommunicator::sendSQLRequest(std::string request)
// {

// }

// void ASCommunicator::checkAndCreateFile(std::string fileName)
// {
//     QFile file(QDir::currentPath() + QString::fromStdString("/" + fileName));

//     if (!file.exists()) {
//         // The file does not exist, create it
//         if (file.open(QIODevice::WriteOnly)) {
//             QTextStream out(&file);
//             out << "";  // Write some initial content
//             file.close();
//             qDebug() << "File created:" << filePath;
//         } else {
//             qDebug() << "Failed to create the file:" << filePath;
//         }
//     } else {
//         qDebug() << "File already exists:" << filePath;
//     }
// }
