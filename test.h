#ifndef TEST_H
#define TEST_H

#include <QJsonArray>
#include <QWidget>

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT

public:
    explicit Test(int testId, QWidget *parent = nullptr);
    ~Test();

    void changeQuestion(int id);

    void offSwitches();

    void setButtonsClickable(bool isClickable);

private slots:
    void on_checkButton_clicked();

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_aCB_stateChanged(int arg1);

    void on_bCB_stateChanged(int arg1);

    void on_cCH_stateChanged(int arg1);

    void on_dCB_stateChanged(int arg1);

private:
    Ui::Test *ui;

    std::vector<bool> canAnswer {true, true, true, true, true};
    std::vector<int> questionsId;
    std::vector<QString> questionsText;
    std::vector<std::vector<QString>> answers;
    std::vector<int> correctAnswers {0, 0, 0, 0, 0};
    std::vector<bool> isAnswerCorrect {false, false, false, false, false};
    int nowQuestion = 0;
};

#endif // TEST_H
