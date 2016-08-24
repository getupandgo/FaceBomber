#ifndef FACESWAPPER_FACESWAP_H
#define FACESWAPPER_FACESWAP_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

class FaceSwap {
public:
    std::vector<cv::Point2f> readPoints(std::string pointsFileName);
    void applyAffineTransform(cv::Mat &warpImage, cv::Mat &src, std::vector<cv::Point2f> &srcTri, std::vector<cv::Point2f> &dstTri);
    void warpTriangle(cv::Mat &img1, cv::Mat &img2, std::vector<cv::Point2f> &t1, std::vector<cv::Point2f> &t2);
    void FaceSwap::calculateDelaunayTriangles(cv::Rect rect, std::vector<cv::Point2f> &points, std::vector< std::vector<int> > &delaunayTri);
};

#endif //FACESWAPPER_FACESWAP_H
