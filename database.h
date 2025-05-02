#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QDate>
#include <QDateTime>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    ~Database();

    bool connect();
    bool initDatabase();
    
    // User management
    bool addUser(const QString &username, const QString &password, const QString &role,
                const QString &fullName, const QString &email, const QString &phone,
                const QString &department);
    bool authenticateUser(const QString &username, const QString &password);
    
    // Employee management
    bool addEmployee(const QString &employeeCode, const QString &fullName,
                    const QString &position, const QString &department,
                    const QDate &hireDate, double salary);
    
    // Document management
    bool addDocument(const QString &documentNumber, const QString &title,
                    const QString &documentType, const QString &content,
                    int authorId);
    bool addDocumentAttachment(int documentId, const QString &fileName,
                             const QString &filePath, const QString &fileType,
                             qint64 fileSize, int uploadedBy);
    bool addDocumentHistory(int documentId, int userId, const QString &action,
                          const QString &description);
    bool addRecipient(int documentId, int userId, const QString &type);
    bool addLetterAttachment(int documentId, const QString &fileName, const QString &filePath, const QString &fileType, qint64 fileSize, int uploadedBy);
    bool addLetterStatus(int documentId, int userId, const QString &status);
    bool addLetterHistory(int documentId, int userId, const QString &action, const QString &description);
    
    // Task management
    bool addTask(const QString &title, const QString &description,
                int assigneeId, int creatorId, const QDate &dueDate,
                const QString &priority);
    
    // Calendar management
    bool addEvent(const QString &title, const QString &description,
                 int creatorId, const QDateTime &startTime,
                 const QDateTime &endTime, const QString &eventType);

private:
    QSqlDatabase db;
    bool createTables();
    bool createCartableTables();
};

#endif // DATABASE_H 