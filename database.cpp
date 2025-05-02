#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QVariant>
#include <QDir>
#include <QStandardPaths>

Database::Database(QObject *parent) : QObject(parent)
{
}

Database::~Database()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool Database::connect()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    
    // Get application data directory
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(dataPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    
    db.setDatabaseName(dataPath + "/office_automation.db");
    
    if (!db.open()) {
        qDebug() << "Error: connection with database failed" << db.lastError().text();
        return false;
    }
    
    return true;
}

bool Database::initDatabase()
{
    if (!connect()) {
        return false;
    }
    bool ok = createTables();
    ok = createCartableTables() && ok;
    QSqlQuery query;
    // Create emails table
    query.exec("CREATE TABLE IF NOT EXISTS emails ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "sender_id INTEGER NOT NULL,"
               "subject TEXT,"
               "body TEXT,"
               "sent_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
               "is_draft INTEGER DEFAULT 0"
               ")");
    // Create email_recipients table
    query.exec("CREATE TABLE IF NOT EXISTS email_recipients ("
               "email_id INTEGER NOT NULL,"
               "user_id INTEGER NOT NULL,"
               "type TEXT NOT NULL,"
               "FOREIGN KEY (email_id) REFERENCES emails(id),"
               "FOREIGN KEY (user_id) REFERENCES users(id)"
               ")");
    // Create email_attachments table
    query.exec("CREATE TABLE IF NOT EXISTS email_attachments ("
               "email_id INTEGER NOT NULL,"
               "file_name TEXT,"
               "file_path TEXT,"
               "file_type TEXT,"
               "file_size INTEGER,"
               "FOREIGN KEY (email_id) REFERENCES emails(id)"
               ")");
    return ok;
}

bool Database::createTables()
{
    QSqlQuery query;
    bool success = true;
    
    // Users table
    if (!query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "username TEXT UNIQUE NOT NULL,"
               "password TEXT NOT NULL,"
               "role TEXT NOT NULL,"
               "full_name TEXT NOT NULL,"
               "email TEXT,"
               "phone TEXT,"
               "department TEXT,"
               "created_at DATETIME DEFAULT CURRENT_TIMESTAMP)")) {
        qDebug() << "Error creating users table:" << query.lastError().text();
        success = false;
    }
               
    // Employees table
    if (!query.exec("CREATE TABLE IF NOT EXISTS employees ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "employee_code TEXT UNIQUE NOT NULL,"
               "full_name TEXT NOT NULL,"
               "position TEXT NOT NULL,"
               "department TEXT NOT NULL,"
               "hire_date DATE NOT NULL,"
               "salary REAL,"
               "status TEXT DEFAULT 'فعال',"
               "created_at DATETIME DEFAULT CURRENT_TIMESTAMP)")) {
        qDebug() << "Error creating employees table:" << query.lastError().text();
        success = false;
    }
               
    // Documents table
    if (!query.exec("CREATE TABLE IF NOT EXISTS documents ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "document_number TEXT UNIQUE NOT NULL,"
               "title TEXT NOT NULL,"
               "document_type TEXT NOT NULL,"
               "content TEXT NOT NULL,"
               "author_id INTEGER NOT NULL,"
               "status TEXT DEFAULT 'فعال',"
               "created_date DATETIME DEFAULT CURRENT_TIMESTAMP,"
               "updated_date DATETIME,"
               "FOREIGN KEY (author_id) REFERENCES users(id))")) {
        qDebug() << "Error creating documents table:" << query.lastError().text();
        success = false;
    }
               
    // Tasks table
    if (!query.exec("CREATE TABLE IF NOT EXISTS tasks ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "title TEXT NOT NULL,"
               "description TEXT,"
               "assignee_id INTEGER NOT NULL,"
               "creator_id INTEGER NOT NULL,"
               "due_date DATE NOT NULL,"
               "priority TEXT DEFAULT 'متوسط',"
               "status TEXT DEFAULT 'در انتظار',"
               "created_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
               "updated_at DATETIME,"
               "FOREIGN KEY (assignee_id) REFERENCES users(id),"
               "FOREIGN KEY (creator_id) REFERENCES users(id))")) {
        qDebug() << "Error creating tasks table:" << query.lastError().text();
        success = false;
    }
               
    // Calendar events table
    if (!query.exec("CREATE TABLE IF NOT EXISTS events ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "title TEXT NOT NULL,"
               "description TEXT,"
               "creator_id INTEGER NOT NULL,"
               "start_time DATETIME NOT NULL,"
               "end_time DATETIME NOT NULL,"
               "event_type TEXT NOT NULL,"
               "status TEXT DEFAULT 'فعال',"
               "created_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
               "FOREIGN KEY (creator_id) REFERENCES users(id))")) {
        qDebug() << "Error creating events table:" << query.lastError().text();
        success = false;
    }

    // Document attachments table
    if (!query.exec("CREATE TABLE IF NOT EXISTS document_attachments ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "document_id INTEGER NOT NULL,"
               "file_name TEXT NOT NULL,"
               "file_path TEXT NOT NULL,"
               "file_type TEXT NOT NULL,"
               "file_size INTEGER NOT NULL,"
               "uploaded_by INTEGER NOT NULL,"
               "uploaded_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
               "FOREIGN KEY (document_id) REFERENCES documents(id),"
               "FOREIGN KEY (uploaded_by) REFERENCES users(id))")) {
        qDebug() << "Error creating document_attachments table:" << query.lastError().text();
        success = false;
    }

    // Document history table
    if (!query.exec("CREATE TABLE IF NOT EXISTS document_history ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "document_id INTEGER NOT NULL,"
               "user_id INTEGER NOT NULL,"
               "action TEXT NOT NULL,"
               "description TEXT,"
               "created_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
               "FOREIGN KEY (document_id) REFERENCES documents(id),"
               "FOREIGN KEY (user_id) REFERENCES users(id))")) {
        qDebug() << "Error creating document_history table:" << query.lastError().text();
        success = false;
    }
               
    return success;
}

bool Database::createCartableTables()
{
    QSqlQuery query;
    bool success = true;
    // Recipients table
    if (!query.exec("CREATE TABLE IF NOT EXISTS recipients ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "document_id INTEGER NOT NULL,"
                   "user_id INTEGER NOT NULL,"
                   "type TEXT NOT NULL,"
                   "FOREIGN KEY (document_id) REFERENCES documents(id),"
                   "FOREIGN KEY (user_id) REFERENCES users(id))")) {
        qDebug() << "Error creating recipients table:" << query.lastError().text();
        success = false;
    }
    // Letter attachments table
    if (!query.exec("CREATE TABLE IF NOT EXISTS letter_attachments ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "document_id INTEGER NOT NULL,"
                   "file_name TEXT NOT NULL,"
                   "file_path TEXT NOT NULL,"
                   "file_type TEXT NOT NULL,"
                   "file_size INTEGER NOT NULL,"
                   "uploaded_by INTEGER NOT NULL,"
                   "uploaded_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
                   "FOREIGN KEY (document_id) REFERENCES documents(id),"
                   "FOREIGN KEY (uploaded_by) REFERENCES users(id))")) {
        qDebug() << "Error creating letter_attachments table:" << query.lastError().text();
        success = false;
    }
    // Letter status table
    if (!query.exec("CREATE TABLE IF NOT EXISTS letter_status ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "document_id INTEGER NOT NULL,"
                   "user_id INTEGER NOT NULL,"
                   "status TEXT NOT NULL,"
                   "updated_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
                   "FOREIGN KEY (document_id) REFERENCES documents(id),"
                   "FOREIGN KEY (user_id) REFERENCES users(id))")) {
        qDebug() << "Error creating letter_status table:" << query.lastError().text();
        success = false;
    }
    // Letter history table
    if (!query.exec("CREATE TABLE IF NOT EXISTS letter_history ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "document_id INTEGER NOT NULL,"
                   "user_id INTEGER NOT NULL,"
                   "action TEXT NOT NULL,"
                   "description TEXT,"
                   "created_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
                   "FOREIGN KEY (document_id) REFERENCES documents(id),"
                   "FOREIGN KEY (user_id) REFERENCES users(id))")) {
        qDebug() << "Error creating letter_history table:" << query.lastError().text();
        success = false;
    }
    return success;
}

bool Database::addUser(const QString &username, const QString &password, const QString &role, 
                      const QString &fullName, const QString &email, const QString &phone, 
                      const QString &department)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, role, full_name, email, phone, department) "
                 "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(role);
    query.addBindValue(fullName);
    query.addBindValue(email);
    query.addBindValue(phone);
    query.addBindValue(department);
    
    if (!query.exec()) {
        qDebug() << "Error adding user:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::authenticateUser(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ? AND password = ? AND status = 'فعال'");
    query.addBindValue(username);
    query.addBindValue(password);
    
    if (!query.exec()) {
        qDebug() << "Error authenticating user:" << query.lastError().text();
        return false;
    }
    
    return query.next();
}

bool Database::addEmployee(const QString &employeeCode, const QString &fullName, 
                         const QString &position, const QString &department, 
                         const QDate &hireDate, double salary)
{
    QSqlQuery query;
    query.prepare("INSERT INTO employees (employee_code, full_name, position, department, hire_date, salary) "
                 "VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(employeeCode);
    query.addBindValue(fullName);
    query.addBindValue(position);
    query.addBindValue(department);
    query.addBindValue(hireDate.toString("yyyy-MM-dd"));
    query.addBindValue(salary);
    
    if (!query.exec()) {
        qDebug() << "Error adding employee:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::addDocument(const QString &documentNumber, const QString &title, 
                         const QString &documentType, const QString &content, 
                         int authorId)
{
    QSqlQuery query;
    query.prepare("INSERT INTO documents (document_number, title, document_type, content, author_id) "
                 "VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(documentNumber);
    query.addBindValue(title);
    query.addBindValue(documentType);
    query.addBindValue(content);
    query.addBindValue(authorId);
    
    if (!query.exec()) {
        qDebug() << "Error adding document:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::addTask(const QString &title, const QString &description, 
                      int assigneeId, int creatorId, const QDate &dueDate, 
                      const QString &priority)
{
    QSqlQuery query;
    query.prepare("INSERT INTO tasks (title, description, assignee_id, creator_id, due_date, priority) "
                 "VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(title);
    query.addBindValue(description);
    query.addBindValue(assigneeId);
    query.addBindValue(creatorId);
    query.addBindValue(dueDate.toString("yyyy-MM-dd"));
    query.addBindValue(priority);
    
    if (!query.exec()) {
        qDebug() << "Error adding task:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::addEvent(const QString &title, const QString &description, 
                       int creatorId, const QDateTime &startTime, 
                       const QDateTime &endTime, const QString &eventType)
{
    QSqlQuery query;
    query.prepare("INSERT INTO events (title, description, creator_id, start_time, end_time, event_type) "
                 "VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(title);
    query.addBindValue(description);
    query.addBindValue(creatorId);
    query.addBindValue(startTime);
    query.addBindValue(endTime);
    query.addBindValue(eventType);
    
    if (!query.exec()) {
        qDebug() << "Error adding event:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::addDocumentAttachment(int documentId, const QString &fileName, 
                                   const QString &filePath, const QString &fileType, 
                                   qint64 fileSize, int uploadedBy)
{
    QSqlQuery query;
    query.prepare("INSERT INTO document_attachments (document_id, file_name, file_path, file_type, file_size, uploaded_by) "
                 "VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(documentId);
    query.addBindValue(fileName);
    query.addBindValue(filePath);
    query.addBindValue(fileType);
    query.addBindValue(fileSize);
    query.addBindValue(uploadedBy);
    
    if (!query.exec()) {
        qDebug() << "Error adding document attachment:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::addDocumentHistory(int documentId, int userId, const QString &action, 
                                const QString &description)
{
    QSqlQuery query;
    query.prepare("INSERT INTO document_history (document_id, user_id, action, description) "
                 "VALUES (?, ?, ?, ?)");
    query.addBindValue(documentId);
    query.addBindValue(userId);
    query.addBindValue(action);
    query.addBindValue(description);
    
    if (!query.exec()) {
        qDebug() << "Error adding document history:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::addRecipient(int documentId, int userId, const QString &type) {
    QSqlQuery query;
    query.prepare("INSERT INTO recipients (document_id, user_id, type) VALUES (?, ?, ?)");
    query.addBindValue(documentId);
    query.addBindValue(userId);
    query.addBindValue(type);
    if (!query.exec()) {
        qDebug() << "Error adding recipient:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::addLetterAttachment(int documentId, const QString &fileName, const QString &filePath, const QString &fileType, qint64 fileSize, int uploadedBy) {
    QSqlQuery query;
    query.prepare("INSERT INTO letter_attachments (document_id, file_name, file_path, file_type, file_size, uploaded_by) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(documentId);
    query.addBindValue(fileName);
    query.addBindValue(filePath);
    query.addBindValue(fileType);
    query.addBindValue(fileSize);
    query.addBindValue(uploadedBy);
    if (!query.exec()) {
        qDebug() << "Error adding letter attachment:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::addLetterStatus(int documentId, int userId, const QString &status) {
    QSqlQuery query;
    query.prepare("INSERT INTO letter_status (document_id, user_id, status) VALUES (?, ?, ?)");
    query.addBindValue(documentId);
    query.addBindValue(userId);
    query.addBindValue(status);
    if (!query.exec()) {
        qDebug() << "Error adding letter status:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::addLetterHistory(int documentId, int userId, const QString &action, const QString &description) {
    QSqlQuery query;
    query.prepare("INSERT INTO letter_history (document_id, user_id, action, description) VALUES (?, ?, ?, ?)");
    query.addBindValue(documentId);
    query.addBindValue(userId);
    query.addBindValue(action);
    query.addBindValue(description);
    if (!query.exec()) {
        qDebug() << "Error adding letter history:" << query.lastError().text();
        return false;
    }
    return true;
} 