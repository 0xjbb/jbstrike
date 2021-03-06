package cfg

import (
	"encoding/json"
	"io/ioutil"
	"log"
	"os"
)

// Struct to parse json cfg data.
type Config struct {
	Database struct {
		DBFile string
	}

	Server struct {
		DefaultPort int
	}

	Listener struct {
		CheckInCmd      string
		DownloadCmd     string
		UploadCmd       string
		ExecCmd         string
		ExecAssemblyCmd string
	}
}

// Load JSON Config file.
func LoadConfig(fileName string) Config {
	config := Config{}
	cfg, err := os.Open(fileName)

	if err != nil {
		log.Fatal(err)
	}

	byteValue, _ := ioutil.ReadAll(cfg)

	//@TODO error check
	json.Unmarshal(byteValue, &config)

	return config
}
