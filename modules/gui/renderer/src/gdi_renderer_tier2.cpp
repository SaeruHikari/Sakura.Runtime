#include "SkrGuiRenderer/gdi_renderer.hpp"
#include "rtm/qvvf.h"

namespace skr {
namespace gdi {

bool GDIRenderer_RenderGraph::support_mipmap_generation() const SKR_NOEXCEPT
{
    return false;
}

} }