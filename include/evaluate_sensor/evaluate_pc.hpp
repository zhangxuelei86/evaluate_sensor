#ifndef EVALUATE_PC_HPP
#define EVALUATE_PC_HPP

#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/PointCloud2.h>
#include <image_transport/image_transport.h>

#include <cv_bridge/cv_bridge.h>

#include "evaluate_sensor/plane_fitting.hpp"

class Evaluator_pc
{
public:
  Evaluator_pc();

  float compute_stat(sensor_msgs::PointCloud2 &msg,
                     const int &w,
                     const int &h,
                     int &nbr);

  void test_corners(sensor_msgs::PointCloud2 &msg,
                    const int &w,
                    const int &h,
                    const int &max);

  void test_hist(sensor_msgs::PointCloud2 &msg,
                 const int &w,
                 const int &h,
                 const float &bin_inc,
                 const int points_nbr=0);

  void compute_plane(sensor_msgs::PointCloud2 &msg,
                     sensor_msgs::PointCloud2::Ptr &final_cloud,
                     geometry_msgs::PoseStamped &pose1);

  void test_temp(cv_bridge::CvImagePtr cv_ptr,
                 const int &w,
                 const int &h);

private:

  Plane_fitting plane_fitting;

  float compute_hist(sensor_msgs::PointCloud2 &msg,
                     const std::vector<float> &mean_val,
                     const int x_min,
                     const int x_max,
                     const int y_min,
                     const int y_max,
                     const int points_nbr=0,
                     bool print=false);

  float compute_mean(sensor_msgs::PointCloud2 &msg,
                     const int &w,
                     const int &h);
};

#endif // EVALUATE_PC_HPP
