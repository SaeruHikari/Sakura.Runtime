#include "module/module_manager.hpp"
#include "platform/filesystem.hpp"
#include "utils/log.h"
#include "task/task.hpp"

int main(int argc, char** argv)
{
    //skr::task::scheduler_t scheduler;
    //scheduler.initialize(skr::task::scheudler_config_t{});
    //scheduler.bind();
    auto moduleManager = skr_get_module_manager();
    std::error_code ec = {};
    auto root = skr::filesystem::current_path(ec);
    moduleManager->mount(root.u8string().c_str());
    moduleManager->make_module_graph("Game", true);
    auto result = moduleManager->init_module_graph(argc, argv);
    if (result != 0) {
        SKR_LOG_ERROR("module graph init failed!");
    }
    moduleManager->destroy_module_graph();
    return 0;
}