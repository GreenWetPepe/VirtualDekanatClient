#include "test.h"
#include "ui_test.h"

#include "server.h"

#include <QJsonArray>
#include <QDebug>

Test::Test(int testId, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Test)
{
    ui->setupUi(this);

    QJsonArray response = Server::sendRequest("http://localhost:5000/api/v1/questions?test_id=" + std::to_string(testId));

    for (int i = 0; i < response.size(); i++)
    {
        int questId = response.at(i).toObject()["question_id"].toInt();
        bool isUsed = false;
        for (int j = 0; j < questionsId.size(); j++)
        {
            if (questId == questionsId[j])
            {
                isUsed = true;
                break;
            }
        }

        if (isUsed) continue;

        questionsId.push_back(questId);
        questionsText.push_back(response.at(i).toObject()["question_text"].toString());
    }

    answers.push_back(std::vector<QString>());
    answers.push_back(std::vector<QString>());
    answers.push_back(std::vector<QString>());
    answers.push_back(std::vector<QString>());
    answers.push_back(std::vector<QString>());

    for (int i = 0; i < response.size(); i++)
    {
        int questId = response.at(i).toObject()["question_id"].toInt();
        for (int j = 0; j < questionsId.size(); j++)
        {
            if (questId == questionsId[j])
            {
                answers[j].push_back(response.at(i).toObject()["question_text"].toString());
                if (response.at(i).toObject()["is_correct"].toBool()) correctAnswers[j] = answers[j].size() - 1;
                break;
            }
        }
    }

    for (int i = 0; i < response.size(); i++)
    {
        int questId = response.at(i).toObject()["question_id"].toInt();
        bool isUsed = false;
        for (int j = 0; j < questionsId.size(); j++)
        {
            if (questId == questionsId[j])
            {
                isUsed = true;
                break;
            }
        }

        if (isUsed) continue;

        questionsId.push_back(questId);
    }
    qDebug() << "OOOO";
}

Test::~Test()
{
    delete ui;
}

void Test::changeQuestion(int id)
{
    setButtonsClickable(true);
    nowQuestion = id;
    offSwitches();

    ui->numberL->setText(QString::fromStdString("Вопрос ") + QString::number(id + 1));

    if (isAnswerCorrect[id]) ui->resultL->setText(QString::fromStdString("0 баллов из 10"));
    else ui->resultL->setText(QString::fromStdString("10 баллов из 10"));

    ui->aL->setText(answers[id][0]);
    ui->bL->setText(answers[id][1]);
    ui->cL->setText(answers[id][2]);
    ui->dL->setText(answers[id][3]);

    if (!canAnswer[id])
    {
        setButtonsClickable(false);
    }
}

void Test::offSwitches()
{
    ui->aCB->setCheckState(Qt::Unchecked);
    ui->bCB->setCheckState(Qt::Unchecked);
    ui->cCB->setCheckState(Qt::Unchecked);
    ui->dCB->setCheckState(Qt::Unchecked);
}

void Test::setButtonsClickable(bool isClickable)
{
    ui->checkButton->setEnabled(isClickable);
    ui->aCB->setEnabled(isClickable);
    ui->bCB->setEnabled(isClickable);
    ui->cCB->setEnabled(isClickable);
    ui->dCB->setEnabled(isClickable);
}

void Test::on_checkButton_clicked()
{
    int ansId = -1;
    if (ui->aCB->isChecked()) ansId = 0;
    if (ui->aCB->isChecked()) ansId = 1;
    if (ui->aCB->isChecked()) ansId = 2;
    if (ui->aCB->isChecked()) ansId = 3;

    if (ansId == -1) return;

    if (correctAnswers[nowQuestion] == ansId) isAnswerCorrect[nowQuestion] = true;
    canAnswer[nowQuestion] = false;

    changeQuestion(nowQuestion);
}


void Test::on_button1_clicked()
{
    changeQuestion(0);
}


void Test::on_button2_clicked()
{
    changeQuestion(1);
}


void Test::on_button3_clicked()
{
    changeQuestion(2);
}


void Test::on_button4_clicked()
{
    changeQuestion(3);
}


void Test::on_button5_clicked()
{
    changeQuestion(4);
}


void Test::on_aCB_stateChanged(int arg1)
{
    offSwitches();
    ui->aCB->setCheckState(Qt::Checked);
}


void Test::on_bCB_stateChanged(int arg1)
{
    offSwitches();
    ui->bCB->setCheckState(Qt::Checked);
}


void Test::on_cCH_stateChanged(int arg1)
{
    offSwitches();
    ui->cCB->setCheckState(Qt::Checked);
}


void Test::on_dCB_stateChanged(int arg1)
{
    offSwitches();
    ui->dCB->setCheckState(Qt::Checked);
}

