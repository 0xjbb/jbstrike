package main

type Listener struct {
	ListenPort int
	gConfig    Config
}

func (list *Listener) Listen() {

}

func HandleAgentHTTPRequests(route string) {
	//Route will be the requested URL query string
	// All strings will be stored in the config.json to make it easier to change
	switch route {
	case gConfig.Listener.CheckInCmd:
		//checkin()
		break
	case gConfig.Listener.DownloadCmd:
		break
	case gConfig.Listener.UploadCmd:
		break
	case gConfig.Listener.ExecCmd:
		break
	case gConfig.Listener.ExecAssemblyCmd:
		break

	}
}
