#include "faceSwapper.h"

FaceSwapper::FaceSwapper(std::string imagePath) : faceDetector(dlib::get_frontal_face_detector()) {
    dlib::deserialize("../shape_predictor_model/shape_predictor_68_face_landmarks.dat") >> shapePredictor;

    dlib::load_image(targetImage, imagePath);
}

void FaceSwapper::swap() {

}