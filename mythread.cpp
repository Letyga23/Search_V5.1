#include "mythread.h"

MyThread::MyThread(QObject* parent)
    : QThread(parent) {}

MyThread::~MyThread()
{
    wait();
}

void MyThread::setTask(std::function<void()> task)
{
    _task = std::move(task);
}

void MyThread::run()
{
    // Проверяем, есть ли задача для выполнения
    if (_task)
    {
        // Выполняем задачу в фоновом потоке
        _task();

        // Имитируем завершение задачи, отправляя сигнал
        emit taskFinished();
    }
}
