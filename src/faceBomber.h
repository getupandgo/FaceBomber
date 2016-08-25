#ifndef FACEBOMBER_FACEBOMBER_H
#define FACEBOMBER_FACEBOMBER_H

#include <opencv2/opencv.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/image_io.h>
#include <iostream>
#include <fstream>

class FaceBomber {
public:
    FaceBomber(std::string imagePath);
    void doFaceBomb();
    void addFaceForBombing(std::string imagePath);
private:
    // methods:
    void extractFace(dlib::array2d<dlib::rgb_pixel> targetImage);
    // fields:
    dlib::array2d<dlib::rgb_pixel> targetImage;
    // Face detector to get bounding boxes for each face in an image.
    dlib::frontal_face_detector faceDetector;
    // Tool for prediction face landmark positions from face bounding box.
    dlib::shape_predictor shapePredictor;
};

#endif //FACEBOMBER_FACEBOMBER_H
