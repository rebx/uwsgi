#include "../../uwsgi.h"

/* gcc `python2.5-config --cflags` -o example_plugin.so -fPIC -shared example_plugin.c */

void uwsgi_init(struct uwsgi_server *uwsgi, char *args){
	fprintf(stderr,"i am the example plugin initialization function with arg: %s\n", args);
}

int uwsgi_request(struct uwsgi_server *uwsgi, struct wsgi_request *wsgi_req, char *buffer) {
	char *http = "HTTP/1.1 200 Ok\r\nContent-type: text/html\r\n\r\n<h1>Hello World</h1>" ;
	wsgi_req->response_size += write(uwsgi->poll.fd, http, strlen(http));

	return 0;
}


int uwsgi_after_request(struct uwsgi_server *uwsgi, struct wsgi_request *wsgi_req, char *buffer) {
	fprintf(stderr,"i am the example plugin after request function\n");
	return 0;
}