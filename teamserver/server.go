package main

type ServerHandler struct {
	ServerPort int
}

func (sHandler *ServerHandler) Start() {
	s := &http.server{}

}

func NewServer(gConfig Config) ServerHandler {
	s := ServerHandler{}

	s.ParseConfig(gConfig)

	return s
}
