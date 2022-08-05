#include <opencv2/opencv.hpp>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <unistd.h>
using namespace std;
int CopyFile(char *SourceFile, char *NewFile)
{
    ifstream in;
    ofstream out;
    in.open(SourceFile, ios::binary); //打开源文件
    if (in.fail())                    //打开源文件失败
    {
        cout << "Error 1: Fail to open the source file." << endl;
        in.close();
        out.close();
        return 0;
    }
    out.open(NewFile, ios::binary); //创建目标文件
    if (out.fail())                 //创建文件失败
    {
        cout << "Error 2: Fail to create the new file." << endl;
        out.close();
        in.close();
        return 0;
    }
    else //复制文件
    {
        out << in.rdbuf();
        out.close();
        in.close();
        return 1;
    }
}
int main(void)
{
    bool ok = false;
    int n[4];
    fstream in("out.txt", ios::in);
    for (int i = 0; i < 4; i++)
        in >> n[i];
    in.close();
    do
    {
        if (!next_permutation(n, n + 4))
        {
            for (int i = 0; i < 4; i++)
                n[i] = i;
            next_permutation(n, n + 4);
        }
        if ((n[1] == 1 && n[2] == 3) || (n[3] == 1 && n[1] == 3) || (n[1] == 1 && n[2] == 3) || (n[3] == 1 && n[1] == 3))
            ok = true;
    } while (!ok);
    fstream out("out.txt", ios::out);
    for (int i = 0; i < 4; i++)
        out << n[i] << "\n";
    out.close();
    CopyFile((char *)"tomorrow.jpg", (char *)"today.jpg");

    cv::Mat seatImage = cv::imread("SEAT.jpg");
    cv::Mat Images[] = {cv::imread("0.jpg"), cv::imread("1.jpg"), cv::imread("2.jpg"), cv::imread("3.jpg")};
    cv::Mat Rects[] = {seatImage(cv::Rect(125, 230, 90, 30)), seatImage(cv::Rect(40, 140, 90, 30)), seatImage(cv::Rect(90, 185, 90, 30)), seatImage(cv::Rect(240, 150, 90, 30))};
    for (int i = 0; i < 4; i++)
        Images[n[i]].copyTo(Rects[i]);

    cv::imwrite("tomorrow.jpg", seatImage);

    return 0;
}