#ifndef ADDRESSHISTOGRAM_H
#define ADDRESSHISTOGRAM_H

#include "render.h"
#include "plot.h"

class address_histogram {
public:
    typedef enum {
        SENDER = 0, RECEIVER, SND_OR_RCV
    } relationship_t;

    class config_t {
    public:
        // generic graph parent config
        plot::config_t graph;
        relationship_t relationship;
        double bar_space_factor;
        int max_bars;
    };

    address_histogram(const config_t conf_) :
        conf(conf_), address_counts() {};

    static const config_t default_config;

private:
    config_t conf;
    std::map<std::string, uint64_t> address_counts;
};

#endif
