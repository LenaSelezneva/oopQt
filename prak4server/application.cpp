#include "application.h"
#include "polinom.h"
#include "common.h"

TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}

void TApplication::recieve(QByteArray msg)
{
    QString answer, s;
    rational a, b, c, x, v;
    root Roots;
    msg>>a>>b>>c;
    TPolinom p(a,b,c);
    int pos = msg.indexOf(separator);
    int t = msg.left(pos).toInt();
    switch (t)
    {
        case VALUE_REQUEST:
            msg = msg.right(msg.length()-pos-1);
            msg>>x;
            v = p.value(x);
            s<<(QString)x<<(QString)v;
            answer<<QString().setNum(VALUE_ANSWER);
            answer += s;
            break;
        case PRINT_CLASSIC_REQUEST:
            p.setPrintMode(EPrintModeClassic);
            s<<p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;
        case PRINT_CANONIC_REQUEST:
            p.setPrintMode(EPrintModeCanonic);
            s<<p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;
        case ROOT_REQUEST:
            Roots = p.roots();
            if(Roots.flag == 0)
            {
                msg = msg.left(msg.length()-pos-1);
                msg>>Roots.x1>>Roots.x2;
                int p;
                QString text;
                s<<(QString)Roots.x1<<(QString)Roots.x2;
                p = s.indexOf(separator);
                text += "x1 = ";
                text += s.left(s.length()-p-1);
                text += " x2 = ";
                text += s.right(s.length()-p-1);
                answer<<QString().setNum(ROOTS_ANSWER);
                answer += text;
            }
            else
            {
                s<<"no roots";
                answer<<QString().setNum(ROOTS_ANSWER);
                answer += s;
            }
            break;

        default: return;
    }
    comm->send(QByteArray().append(answer));
}
