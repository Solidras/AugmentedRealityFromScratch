//
// Created by Simon on 22/12/2020.
//

#ifndef AR_TAGDETECTION_HPP
#define AR_TAGDETECTION_HPP

#include <vector>
#include <opencv2/core.hpp>

#include "ARTag.hpp"
#include "Tracking.hpp"

namespace arfs
{
    /**
     * @brief Perform a tag detection algorithm on an image.
     */
    class TagDetection
    {
    public:
        /**
         * @brief Construct a tag detection with the tag to recognize.
         * @param tag
         * @param verbose shows debug information if true (default false)
         */
        explicit TagDetection(const arfs::ARTag& tag, bool verbose = false) : m_tagToDetect(tag), m_verbose(verbose), m_perfectMatchingTagFound(false), m_requirementLevel(55)
        {};

        /**
         * @brief Update the detected tag.
         * @details Use a tracking solution to track tag along the image. Perform a full detection with the first image and if the tracking is lost.
         * @param frame
         * @return the detected tag
         */
        std::vector<cv::Point> update(const cv::Mat& frame);

    private:
        arfs::ARTag m_tagToDetect;
        std::vector<cv::Point> m_tagCorners{};
        arfs::Tracking m_tracking{};
        bool m_perfectMatchingTagFound;
        /**
         * Number of minimum matching cells to consider candidate tag to be validated
         */
        int m_requirementLevel;
        bool m_verbose;
        static constexpr double m_minimumDistance{2};

        void fullDetection(const cv::Mat& frame);

        static std::vector<std::vector<cv::Point>> extractTagCandidates(const cv::Mat& frame);

        bool recognizeTag(const cv::Mat& frame, std::vector<cv::Point>& candidate, bool needPerfectTagMatching = false);

        cv::Mat gaussianDeblurring(cv::Mat& imgIn);
    };
}

#endif //AR_TAGDETECTION_HPP
