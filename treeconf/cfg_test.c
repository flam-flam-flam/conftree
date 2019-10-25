/**
 * @author: ideawu
 * @url: http://www.ideawu.net
 * @description: C 语言使用配置文件库.
 */
#include <stdio.h>
#include "log.h"
#include "config.h"

int main(int argc, char **argv){
	struct config *cfg, *c;

	cfg = cfg_load_file("cfg_test.conf");
	if(!cfg){
		return 0;
	}

	log_debug("start");

	cfg_print(cfg, stdout);

	printf("\n");
	printf("proxy.php.host = %s\n", cfg_getstr(cfg, "proxy.php.host"));
	printf("proxy.php.port = %d\n", cfg_getnum(cfg, "proxy.php.port"));
	printf("cgi.pl = %s\n", cfg_getstr(cfg, "cgi.pl"));
	printf("\n");

	c = cfg_get(cfg, "author");
	printf("author : %s\n", cfg_str(c));
	printf("url : %s\n", cfg_getstr(c, "url"));
	printf("\n");

	log_debug("end");

	cfg_free(cfg);

	return 0;
}
