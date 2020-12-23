//
// Created by Simon on 22/12/2020.
//

#ifndef AR_SCENE_HPP
#define AR_SCENE_HPP

#include <vector>
#include "Object.hpp"
#include "Camera.hpp"

namespace arfs
{
    class Scene
    {
    public:
        explicit Scene(const arfs::Camera& camera) : m_camera(camera)
        {};

        void addObject(const std::string& filename);
        void rotate(double xAngle, double yAngle, double zAngle);
        void scale(double scale);

        //TODO: Add scale, rotate and remove only one object

        arfs::Camera& getCamera()
        { return m_camera; }

        arfs::Camera getCamera() const
        { return m_camera; }

        std::vector<arfs::Object> getObjects() const
        { return m_objects; }

    private:
        std::vector<arfs::Object> m_objects{};
        arfs::Camera m_camera{};
    };
}

#endif //AR_SCENE_HPP