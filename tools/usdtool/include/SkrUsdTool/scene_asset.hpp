#pragma once
#include <EASTL/functional.h>
#include "platform/configure.h"
#include "containers/hashmap.hpp"
#include "SkrUsdTool/module.configure.h"
#include "SkrToolCore/asset/importer.hpp"
#include "SkrToolCore/asset/cooker.hpp"
#ifndef __meta__
    #include "SkrUsdTool/scene_asset.generated.h"
#endif

namespace skd sreflect
{
namespace asset sreflect
{
sreflect_struct("guid" : "4F0E4239-A07F-4F48-B54F-FBF406C60DC3", "serialize" : "json")
SKRUSDTOOL_API SUSDSceneImporter final : public SImporter
{
    sattr("no-default" : true)
    skr::string assetPath;
    // mapping from asset path to resource
    // by default importer will resolve the path to find resource if redirector is not exist
    skr::flat_hash_map<skr::string, skr_guid_t, skr::hash<skr::string>> redirectors;
    void* Import(skr_io_ram_service_t*, SCookContext* context) override;
    void Destroy(void* resource) override;
}
sregister_importer();

sreflect_struct("guid" : "A4E9937D-792B-4ABB-BFDB-42066B92E910")
SKRUSDTOOL_API SUSDSceneCooker final : public SCooker 
{ 
    bool Cook(SCookContext * ctx) override;
    uint32_t Version() override { return kDevelopmentVersion; }
}
sregister_default_cooker("EFBA637E-E7E5-4B64-BA26-90AEEE9E3E1A");
} // namespace asset
} // namespace skd