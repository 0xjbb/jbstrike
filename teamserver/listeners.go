package main

type Listener struct {
	ListenPort int
	gConfig    Config
}

func (list *Listener) Listen() {

}

func HandleAgentHTTPRequests(route string) {

	switch route {
	case gConfig.Listener.CheckInCmd:
		checkin()
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
