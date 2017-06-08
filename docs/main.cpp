#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <conio.h>
#include <iostream>
#include "SerialClass.h"

#define TOP_BORDER 160
#define BOTTOM_BORDER 250
#define LEFT_BORDER 250
#define RIGHT_BORDER 220

using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame );

String face_cascade_name = "haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

String window_name = "Face_detection";

Serial* SP;
char* buffer;

bool done;
bool mode;
int command;


int main( void )
{
    done = false;
    mode = true;

    SP = new Serial("\\\\.\\COM4");
    if (SP->IsConnected())
        printf("Connected");
    buffer="i";
    SP->WriteData(buffer, 1);
    command = 0;
    Sleep(500);

    //
    VideoCapture capture;
    capture.open(0);
    Mat frame;

    if( !face_cascade.load( face_cascade_name ) )
    {
        printf("--(!)Error loading face cascade\n");
        return -1;
    };
    if( !eyes_cascade.load( eyes_cascade_name ) )
    {
        printf("--(!)Error loading eyes cascade\n");
        return -1;
    };
    if ( ! capture.isOpened() )
    {
        printf("--(!)Error opening video capture\n");
        return -1;
    }
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            printf(" (!) No captured frame  Break!");
            break;
        }
        detectAndDisplay( frame );
        int c = waitKey(10);
        if( (char)c == 27 )
        {
            break;
        }
    }

    buffer="p";
    SP->WriteData(buffer, 1);
    Sleep(500);

    return 0;
}

int pos[10][2]; // 1st - faces number, 2nd - coordinates


void detectAndDisplay( Mat frame )
{

    char direction, selectMode;

    std::vector<Rect> faces;
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    pos[0][0] = 200;
    pos[0][1] = 200;

    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(100, 100) );

    for( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 0, 13, 26), 4, 8, 0 );
        circle(frame,center,1,Scalar( 0, 100, 105 ), 4, 8, 0);
        Mat faceROI = frame_gray( faces[i] );
        std::vector<Rect> eyes;

        Point before(2*(faces[i].x + faces[i].width/2) - pos[i][0], 2*(faces[i].y + faces[i].height/2) - pos[i][1]);
        //line(frame, before, center, Scalar(0, 13, 26), 4, 8, 0);
        pos[i][0] = faces[i].x + faces[i].width/2;
        pos[i][1] = faces[i].y + faces[i].height/2;
    }

    if(mode)
    {
        if ((faces.size() == 0 ) && (command!=0))
        {
            buffer= "0";
            command = 0;
            SP->WriteData(buffer, 1);
            std::cout << "9 - NONE, NONE, false" << std::endl;
            Sleep(500);
        }

        if ((faces.size()!=0) && (pos[0][0] < RIGHT_BORDER) && (command!=3) && (pos[0][1] > TOP_BORDER) && (pos[0][1] < BOTTOM_BORDER))
        {
            buffer= "3";
            command = 3;
            SP->WriteData(buffer, 1);
            std::cout << "3 - RIGHT, NONE" << std::endl;
            Sleep(500);
        }
        else if ((faces.size()!=0) && (pos[0][0] > LEFT_BORDER) && (command != 4)&& (pos[0][1] > TOP_BORDER) && (pos[0][1] < BOTTOM_BORDER))
        {
            buffer= "4";
            command = 4;
            SP->WriteData(buffer, 1);
            std::cout << "4 - LEFT, NONE" << std::endl;
            Sleep(500);
        }
        else if ((faces.size()!=0) && (pos[0][0] <= LEFT_BORDER) && (pos[0][0] >= RIGHT_BORDER) && (command!=0)&& (pos[0][1] > TOP_BORDER) && (pos[0][1] < BOTTOM_BORDER))
        {
            buffer= "0";
            command = 0;
            SP->WriteData(buffer, 1);
            std::cout << "0 - NONE, NONE" << std::endl;
            Sleep(500);
        }
        else if ((faces.size()!=0) && (pos[0][0] <= LEFT_BORDER) && (pos[0][0] >= RIGHT_BORDER) && (command!=1)&& (pos[0][1] < TOP_BORDER))
        {
            buffer= "1";
            command = 1;
            SP->WriteData(buffer, 1);
            std::cout << "1 - NONE, UP" << std::endl;
            Sleep(500);
        }
        else if ((faces.size()!=0) && (pos[0][0] <= LEFT_BORDER) && (pos[0][0] >= RIGHT_BORDER) && (command!=2)&& (pos[0][1] > BOTTOM_BORDER))
        {
            buffer= "2";
            command = 2;
            SP->WriteData(buffer, 1);
            std::cout << "2 - NONE, DOWN" << std::endl;
            Sleep(500);
        }
        else if ((faces.size() != 0) && (pos[0][0] > LEFT_BORDER)  && (command!=8)&& (pos[0][1] > BOTTOM_BORDER))
        {
            buffer= "8";
            command = 8;
            SP->WriteData(buffer, 1);
            std::cout << "8 - LEFT, DOWN" << std::endl;
            Sleep(500);
        }
        else if ((faces.size() != 0) && (pos[0][0] < RIGHT_BORDER)  && (command!=6)&& (pos[0][1] > BOTTOM_BORDER))
        {
            buffer= "6";
            command = 6;
            SP->WriteData(buffer, 1);
            std::cout << "6 - RIGHT, DOWN" << std::endl;
            Sleep(500);
        }//
        else if ((faces.size() != 0) && (pos[0][0] > LEFT_BORDER)  && (command!=7)&& (pos[0][1] < TOP_BORDER))
        {
            buffer= "7";
            command = 7;
            SP->WriteData(buffer, 1);
            std::cout << "7 - LEFT, UP" << std::endl;
            Sleep(500);
        }
        else if ((faces.size() != 0) && (pos[0][0] < RIGHT_BORDER)  && (command!=5)&& (pos[0][1]  < TOP_BORDER))
        {
            buffer= "5";
            command = 5;
            SP->WriteData(buffer, 1);
            std::cout << "5 - RIGHT, UP" << std::endl;
            Sleep(500);
        }
    }
    imshow( window_name, frame);
}
