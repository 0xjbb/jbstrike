package listeners

import (
	"github.com/0xjbb/jbstrike/pkg/cfg"
	"github.com/gorilla/mux"
	"net/http"
)

type Listener struct {
	ListenPort int
	gConfig    cfg.Config
	s          *http.Server
}

func (nList *Listener) Listen() {
	router := mux.NewRouter()

	router.PathPrefix("/agent/{uuid}/{function}").HandlerFunc(HandleAgentHTTPRequests(nList.gConfig))

	nList.s = &http.Server{
		Handler: router,
		Addr:    ":" + string(nList.ListenPort),
	}

	go nList.s.ListenAndServe()

}

func NewListener(port int, gConfig cfg.Config) Listener {
	l := Listener{}

	l.ListenPort = port
	return l
}

func HandleAgentHTTPRequests(gConfig cfg.Config) func(w http.ResponseWriter, r *http.Request) {
	//Route will be the requested URL query string
	// All strings will be stored in the cfg.json to make it easier to change
	return func(w http.ResponseWriter, r *http.Request) {
		vars := mux.Vars(r)

		//uuid := vars["uuid"]
		route := vars["function"]

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
}
