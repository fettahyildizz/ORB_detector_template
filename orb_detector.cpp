	cv::Mat img_1, img2;
	cv::Mat descriptors_1, descriptors_2;
      cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create();
    	 	 				// fastThreshold ;
      cv::Ptr<cv::DescriptorExtractor> descriptor = cv::ORB::create();

      // use this if you are in OpenCV2
      // Ptr<FeatureDetector> detector = FeatureDetector::create ( "ORB" );
      // Ptr<DescriptorExtractor> descriptor = DescriptorExtractor::create ( "ORB"
      // );
      
      cv::Ptr<cv::DescriptorMatcher> matcher =
      cv::DescriptorMatcher::create("BruteForce-Hamming");
      detector->detect(img_1, keypoints_1);
      detector->detect(img_2, keypoints_2);

      descriptor->compute(img_1, keypoints_1, descriptors_1);
      descriptor->compute(img_2, keypoints_2, descriptors_2);

      std::vector<cv::DMatch> match, matches;

      matcher->match(descriptors_1, descriptors_2, match);

      double min_dist = 10000, max_dist = 0;


      for (int i = 0; i < descriptors_1.rows; i++) {
        double dist = match[i].distance;
        if (dist < min_dist)
          min_dist = dist;
        if (dist > max_dist)
          max_dist = dist;
      }

      //printf("-- Max dist : %f \n", max_dist);
      printf("-- Min dist : %f \n", min_dist);

      for (int i = 0; i < descriptors_1.rows; i++) {
        if (match[i].distance <= std::min(2 * min_dist+5 , 42.0)) { //std::max
          matches.push_back(match[i]);
        }
      }
      
      sort( matches.begin( ), matches.end( ), [ ]( const cv::DMatch& lhs, const cv::DMatch& rhs )
      {
        return lhs.distance < rhs.distance;
      });
