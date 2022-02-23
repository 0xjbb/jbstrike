package main

type ServerHandler struct {
	ServerPort int
}

func (sHandler *ServerHandler) Start() {
	s := &http.server{}

}

// Add some error checknig later
func (sHandler *ServerHandler) ParseConfig(sConfig Config) {
	sHandler.ServerPort = sConfig.Server.DefaultPort
}

func NewServer(gConfig Config) ServerHandler {
	s := ServerHandler{}

	s.ParseConfig(gConfig)

	return s
}
