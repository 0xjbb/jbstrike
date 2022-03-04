package cmd

import (
	"fmt"
	"github.com/desertbit/grumble"
)

func init() {
	App.AddCommand(&grumble.Command{
		Name: "sessions",
		Help: "List current sessions",
		Run: func(c *grumble.Context) error {
			fmt.Println("This is a test.")
			return nil
		},
	})

}
