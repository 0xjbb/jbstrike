package main

func main() {
	gConfig := LoadConfig("~/.jbstrike/conf/config.json")

	server := NewServer(gConfig)
	server.Start()
}
