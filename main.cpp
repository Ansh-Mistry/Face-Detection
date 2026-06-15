#include <opencv2/opencv.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    VideoCapture cap(0);
    cap.set(CAP_PROP_FRAME_WIDTH, 1920);
    cap.set(CAP_PROP_FRAME_HEIGHT, 1080);
    Mat img, mirror, gray, smallGray;

    CascadeClassifier faceCascade;
    faceCascade.load("../haarcascade_frontalface_default.xml");

    if(faceCascade.empty()){
        cout<<"XML not loaded. "<<endl;
        return -1;
    }

    vector<Rect> faces;

    while(true){
        cap.read(img);
        if(img.empty()){continue; }
        flip(img,mirror,1);

        cvtColor(mirror, gray, COLOR_BGR2GRAY);

        double scale = 0.25; 
        resize(gray, smallGray, Size(), scale, scale);
        equalizeHist(smallGray, smallGray);

        faceCascade.detectMultiScale(smallGray, faces, 1.2, 5, 0, Size(30,30));

        for(int i = 0; i < faces.size(); i++){
            Rect scaledFace(
                cvRound(faces[i].x/scale),
                cvRound(faces[i].y/scale),
                cvRound(faces[i].width/scale),
                cvRound(faces[i].height/scale)
            );
            rectangle(mirror, scaledFace.tl(), scaledFace.br(), Scalar(255,0,0), 3);
        }

        imshow("webcam", mirror);
        if(waitKey(1) == 27) {break;}
    }
    return 0;
}
