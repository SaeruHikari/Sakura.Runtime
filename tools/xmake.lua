set_project("SakuraTool")


target("SkrTool")
    set_kind("shared")
    add_files("core/src/**.cpp")
    add_deps("SkrRT")
    add_includedirs("core/include", {public = true})
    add_rules("c++.reflection", {
        files = {"core/**.h", "core/**.hpp"},
        rootdir = "core/"
    })

target("SkrCompiler")
    add_rules("grpc.cpp")
    set_kind("binary")
    add_deps("SkrTool", "GameRT")
    add_files("compiler/**.proto")
    add_files("compiler/**.cpp")
    add_links("absl_bad_any_cast_impl","absl_bad_optional_access","absl_bad_variant_access","absl_base","absl_city","absl_civil_time","absl_cord","absl_cordz_functions","absl_cordz_handle","absl_cordz_info","absl_cordz_sample_token","absl_cord_internal","absl_debugging_internal","absl_demangle_internal","absl_examine_stack","absl_exponential_biased","absl_failure_signal_handler","absl_flags","absl_flags_commandlineflag","absl_flags_commandlineflag_internal","absl_flags_config","absl_flags_internal","absl_flags_marshalling","absl_flags_parse","absl_flags_private_handle_accessor","absl_flags_program_name","absl_flags_reflection","absl_flags_usage","absl_flags_usage_internal","absl_graphcycles_internal","absl_hash","absl_hashtablez_sampler","absl_int128","absl_leak_check","absl_leak_check_disable","absl_log_severity","absl_low_level_hash","absl_malloc_internal","absl_periodic_sampler","absl_random_distributions","absl_random_internal_distribution_test_util","absl_random_internal_platform","absl_random_internal_pool_urbg","absl_random_internal_randen","absl_random_internal_randen_hwaes","absl_random_internal_randen_hwaes_impl","absl_random_internal_randen_slow","absl_random_internal_seed_material","absl_random_seed_gen_exception","absl_random_seed_sequences","absl_raw_hash_set","absl_raw_logging_internal","absl_scoped_set_env","absl_spinlock_wait","absl_stacktrace","absl_status","absl_statusor","absl_strerror","absl_strings","absl_strings_internal","absl_str_format_internal","absl_symbolize","absl_synchronization","absl_throw_delegate","absl_time","absl_time_zone","address_sorting","cares","crypto","gpr","grpc++","grpc++_alts","grpc++_error_details","grpc++_reflection","grpc++_unsecure","grpc","grpcpp_channelz","grpc_plugin_support","grpc_unsecure","libprotobuf-lite","libprotobuf","libprotoc","re2","ssl","upb")
    if(is_os("windows")) then 
        add_links("zlibstatic")
    end
    add_rules("c++.reflection", {
        files = {"compiler/**.h", "compiler/**.hpp"},
        rootdir = "compiler/"
    })
    on_config(function (target, opt)
        for _, dep in pairs(target:deps()) do
            local toolgendir = path.join(dep:autogendir({root = true}), dep:plat(), "tool/generated", dep:name())
            if os.exists(toolgendir) then
                target:add("includedirs", toolgendir)
                local cppfiles = os.files(path.join(toolgendir, "/**.cpp"))
                for _, file in ipairs(cppfiles) do
                    target:add("files", file)
                end
            end
        end
    end)