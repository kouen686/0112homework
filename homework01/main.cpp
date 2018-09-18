#include<QDebug>
#include<QList>

typedef quint8 byte;
typedef quint32 word;
#define  HHI(xxx)  ((byte) ((word)(xxx) & 255))//取32位数中的最高8位
#define  LHI(xxx)  ((byte) ((word)(xxx) >> 8))//取32位数中的次高8位
#define  HLO(xxx)  ((byte) ((word)(xxx) >> 16))//取32位数的次低8位
#define  LLO(xxx)  ((byte) ((word)(xxx) >> 24))//取32位数中的最低8位
#define  MAX(x, y)  ( ((x) > (y)) ? (x) : (y) )//取两数中最大值
#define  MIN(x, y)  ( ((x) < (y)) ? (x) : (y) )//取两数中最小值
#define n 0x12345678//定义32位无符号整型数
int main()
{
    //QCoreApplication a(argc, argv);
    QList<quint8> vaules;//定义一个8位无符号整型结构体
    vaules<<LLO(n)<<HLO(n)<<LHI(n)<<HHI(n);//取出最低8位、次低8位、次高8位、最高8位,并存入vaules这个数组中
    qDebug("原始值：  0x%x==%d",n,n);//输出原数
    qDebug("最高8位：0x%x==%d ",HHI(n),HHI(n));//输出最高8位
    qDebug("次高8位：0x%x==%d ",LHI(n),LHI(n));//输出次高8位
    qDebug("次低8位：0x%x==%d ",HLO(n),HLO(n));//输出次低8位
    qDebug("最低8位：0x%x==%d ",LLO(n),LLO(n));//输出最低8位
    qDebug("最高8位和次高8位的最大值：0x%x<%d>",MAX(HHI(n), LHI(n)),MAX(HHI(n), LHI(n)));//输出最高8位和次高8位的最大值
    qDebug("次低8位和最低8位的最小值：0x%x<%d>",MIN(HLO(n), LLO(n)),MIN(HLO(n), LLO(n)));//输出次低8位和最低8位的最小值
    quint32 m=(LHI(n)&0xff)<<0|(LLO(n)&0xff)<<8|(HHI(n)&0xff)<<16|(HLO(n)&0xff)<<24;
    qDebug("重新组合后的数值：0x%x<%d>",m,m);//用16进制和10进制分别输出重新组合后的数组
    qDebug()<<"排序前："<<vaules;//输出排序前的vaules数组
    std::sort(vaules.begin(),vaules.end(),std::greater<quint8>());//将vaules数组进行降序排序
    qDebug()<<"排序后："<<vaules;//输出排序后的vaules数组
    return 0;
}


