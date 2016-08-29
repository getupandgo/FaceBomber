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
    FaceBomber();
    void doFaceBomb(std::string imagePath);
    void addFaceForBombing(std::string faceName, std::string imagePath);
private:
    // methods:
    void getAllFacesForBombing();
    std::vector<dlib::full_object_detection> extractFacePoses(dlib::array2d<dlib::rgb_pixel> &targetImage);
    // fields:
    std::map <std::string, std::string> facesForBombing;
    dlib::array2d<dlib::rgb_pixel> targetImage;
    // Face detector to get bounding boxes for each face in an image.
    dlib::frontal_face_detector faceDetector;
    // Tool for prediction face landmark positions from face bounding box.
    dlib::shape_predictor shapePredictor;
};

#endif //FACEBOMBER_FACEBOMBER_H
