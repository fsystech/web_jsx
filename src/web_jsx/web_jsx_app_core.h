/**
* Copyright (c) 2018, SOW (https://www.safeonline.world). (https://github.com/RKTUXYN) All rights reserved.
* @author {SOW}
* Copyrights licensed under the New BSD License.
* See the accompanying LICENSE file for terms.
*/
//4:02 PM 2/3/2019
#if defined(_MSC_VER)
#pragma once
#endif//!_MSC_VER
#if !defined(_web_jsx_app_core_h)
#	define _web_jsx_app_core_h
#	include "util.h"
#	include <string>
#	include "core/template_info.h"
typedef struct {
	std::string* ex_dir;
	std::string* ex_name;
	const char*execute_path;
	int is_fserver;
} app_ex_info;

#if !defined(_free_app_info)
#define _free_app_info(inf)\
_free_obj(inf->ex_dir);\
_free_obj(inf->ex_name);\
inf->execute_path = NULL;\
delete inf; inf = NULL;
#endif//!_free_app_info

namespace web_jsx {
	namespace app_core {
		void run__js_scrip(const char* content_type, std::string&root_dir, const app_ex_info aei, req_method&method, template_result& tr, const char*env_path, char **envp);
		void prepare_response(const char* content_type, const char*path_translated, const app_ex_info aei, req_method&method, const char* path_info, const char*env_path, char **envp);
#if defined(FAST_CGI_APP)
		void run__js_scrip(const char* content_type, std::string&root_dir, const app_ex_info aei, req_method&method, template_result& tr);
		void prepare_response(const char* content_type, const char*path_translated, const app_ex_info aei, req_method&method, const char* path_info);
#endif//!FAST_CGI_APP
		void prepare_console_response(int argc, char *argv[], int ireq);
	}
}

#endif//_util_h