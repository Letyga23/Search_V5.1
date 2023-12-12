#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <functional>

class MyThread : public QThread
{
    Q_OBJECT
    std::function<void()> _task;

public:
    MyThread(QObject* parent = nullptr);
    ~MyThread() override;
    void setTask(std::function<void()> task);

signals:
    void taskFinished();

protected:
    void run() override;
};

#endif // MYTHREAD_H
