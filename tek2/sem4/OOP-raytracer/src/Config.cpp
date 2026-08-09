/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-jules.dufraiche [WSL: Ubuntu]
** File description:
** Config
*/

#include "Config.hpp"
#include "Error.hpp"

raytracer::Config::Config(const std::string &fp)
{
    libconfig::Config cfg;
    cfg.readFile(fp.c_str());
    parseCamera(cfg);
    parseShape(cfg);
    parseLight(cfg);
}

void raytracer::Config::parseLight(libconfig::Config &cfg)
{
    const libconfig::Setting &lights = cfg.lookup("lights.lights");
    double x, y, z;

    for (const auto &lightSettings: lights) {
        std::string str;
        if (lightSettings.lookupValue("type", str)) {
            if (str == "point" || str == "directional") {
                _lighttype.push_back(str);
            }
        }
        if (lightSettings.exists("position")) {
            const libconfig::Setting &position = lightSettings["position"];
            if (position.lookupValue("x", x) && position.lookupValue("y", y) && position.lookupValue("z", z)) {
                _lightpos.push_back({x, y, z});
            }
        }
        if (lightSettings.exists("intensity")) {
            double intensity;
            if (lightSettings.lookupValue("intensity", intensity)) {
                _lightintensity.push_back(intensity);
            }
        }
        if (lightSettings.exists("color")) {
            const libconfig::Setting &color = lightSettings["color"];
            double r, g, b;
            if (color.lookupValue("r", r) && color.lookupValue("g", g) && color.lookupValue("b", b)) {
                _lightcolor.push_back({r, g, b});
            }
        }
    }
}

void raytracer::Config::parseShape(libconfig::Config &cfg)
{
    const libconfig::Setting &settings = cfg.lookup("primitives");
    const libconfig::Setting &shapes = settings.lookup("shapes");

    _renderer = settings.lookup("renderer").c_str();
    _output = settings.lookup("output").c_str();

    if (_renderer.empty() || _output.empty())
        throw raytracer::Error("Renderer or output not found");

    for (const auto &shapeSettings: shapes) {
        std::string type;
        if (shapeSettings.lookupValue("type", type)) {
            if (type == "sphere" || type == "plane") {
                _shapes.push_back(type);
            } else {
                throw raytracer::Error("Shape type not found");
            }
        }
    }
}

void raytracer::Config::parseCamera(libconfig::Config &cfg)
{
    double height;
    double width;
    double posX, posY, posZ;
    double rotX, rotY, rotZ;

    const libconfig::Setting &camera = cfg.lookup("camera");
    const libconfig::Setting &resolution = camera.lookup("resolution");
    const libconfig::Setting &position = camera.lookup("position");
    const libconfig::Setting &rotation = camera.lookup("rotation");

    _fov = camera.lookup("fov");
    if (resolution.lookupValue("width", width) && resolution.lookupValue("height", height))
        _reso = std::make_pair(width, height);
    if (position.lookupValue("x", posX) && position.lookupValue("y", posY) && position.lookupValue("z", posZ))
        _campos = {posX, posY, posZ};
    if (rotation.lookupValue("x", rotX) && rotation.lookupValue("y", rotY) && rotation.lookupValue("z", rotZ))
        _camrot = {rotX, rotY, rotZ};
}

raytracer::Config::~Config() {}
