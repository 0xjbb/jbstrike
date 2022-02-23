package main

type ServerHandler struct {
	ServerPort int
}

func (sHandler *ServerHandler) Start() {
	s := &http.server{}

}
