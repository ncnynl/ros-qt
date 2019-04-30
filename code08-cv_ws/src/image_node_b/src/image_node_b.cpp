 #include "ros/ros.h"  
    #include "image_transport/image_transport.h"  
    #include "cv_bridge/cv_bridge.h"  
    #include "sensor_msgs/image_encodings.h"  
    #include <opencv2/imgproc/imgproc.hpp>  
    #include <opencv2/highgui/highgui.hpp>  
    #include <iostream>  
      
    namespace enc = sensor_msgs::image_encodings;  
      
    /*准备再次发布的图像显示到本窗口*/  
    //static const char OUT_WINDOW[] = "Image Out";  
    /*读取订阅的图像并显示到本窗口*/  
    //static std::string IN_WINDOW = "Image In";  
      
    class ImageConvertor  
    {  
        ros::NodeHandle nh_;  
        image_transport::ImageTransport it_;  
        image_transport::Subscriber image_sub_;  
        image_transport::Publisher image_pub_;  
          
        public:  
        ImageConvertor():it_(nh_){  
            /*发布主题out*/  
            image_pub_ = it_.advertise("node_b", 1); 
                    /*订阅主题camera/image*/  
            image_sub_ = it_.subscribe("node_a", 1, &ImageConvertor::ImageCb, this);  
            //cv::namedWindow(OUT_WINDOW, CV_WINDOW_AUTOSIZE);  
            //cv::namedWindow(IN_WINDOW, CV_WINDOW_AUTOSIZE);  
        }  
      
        ~ImageConvertor()  
        {  
            //cv::destroyWindow(IN_WINDOW);  
            //cv::destroyWindow(OUT_WINDOW);  
        }  
      
        void ImageCb(const sensor_msgs::ImageConstPtr& msg)  
        {  
            cv_bridge::CvImagePtr cv_ptr;  
      
            try  
            {  
                 /*转化成CVImage*/  
                         cv_ptr = cv_bridge::toCvCopy(msg, enc::BGR8);  
                         cv::imshow("node_b listener from node_a",cv_ptr->image);
                         cv::waitKey(30);
            }  
      
            catch (cv_bridge::Exception& e)  
            {  
                ROS_ERROR("cv_bridge exception is %s", e.what());  
                return;  
            }  
      
            if(cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)  
              cv::circle(cv_ptr->image, cv::Point(50,50), 10, CV_RGB(255,0,0));  
      
            //cv::imshow(IN_WINDOW, cv_ptr->image);  
            cv::Mat img_out;  
      
                    /*convert RGB to GRAY*/  
                    cv::cvtColor(cv_ptr->image, img_out, CV_RGB2GRAY);  
            //cv::imshow(OUT_WINDOW, img_out);  
            cv::imshow("node_b talker to node_c",img_out);
            cv::waitKey(3);  
                    /*转化成ROS图像msg发布到主题out*/  
            image_pub_.publish(cv_ptr->toImageMsg());  
        }  
      
      
    };  
      
      
    int main(int argc, char** argv)  
    {  
        ros::init(argc, argv, "image_node_b");  
        ImageConvertor ic;  
        ros::spin();  
          
        return 0;  
    }

