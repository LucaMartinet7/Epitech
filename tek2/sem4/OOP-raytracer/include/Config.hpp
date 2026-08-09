/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-jules.dufraiche [WSL: Ubuntu]
** File description:
** Config
*/

#ifndef CONFIG_HPP_
    #define CONFIG_HPP_

    #include <iostream>
    #include <vector>
    #include <libconfig.h++>

namespace raytracer {
    class Config {
        public:
            Config(const std::string &fp);
            ~Config();

            void parseShape(libconfig::Config &cfg);
            void parseCamera(libconfig::Config &cfg);
            void parseLight(libconfig::Config &cfg);
            //camera
            double _fov;
            std::pair<double, double> _reso;
            std::vector<double> _campos;
            std::vector<double> _camrot;
            //shape
            std::string _renderer;
            std::string _output;
            std::vector<std::string> _shapes;
            //light
            std::vector<std::string> _lighttype;
            std::vector<std::vector<double>> _lightpos;
            std::vector<double> _lightintensity;
            std::vector<std::vector<double>> _lightcolor;
        protected:

        private:

    };
}

#endif /* !CONFIG_HPP_ */
