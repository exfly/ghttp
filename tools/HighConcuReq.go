package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"sync"
)

func main() {
	wg := sync.WaitGroup{}
	mut := sync.Mutex{}

	statistics := map[string]int{}
	timesn := 300

	wg.Add(timesn)
	for i := 0; i < timesn; i++ {
		go func() {
			_, err := req("http://localhost:8080/")
			// _, err := req("https://www.ibm.com")
			if err != nil {
				mut.Lock()
				v, _ := statistics["err"]
				v++
				statistics["err"] = v
				mut.Unlock()
				println(err.Error())
			} else {
				mut.Lock()
				v, _ := statistics["ok"]
				v++
				statistics["ok"] = v
				mut.Unlock()
			}
			// print(len(string(res)))
			wg.Done()
		}()
	}
	wg.Wait()
	println("\nstatistics:")
	fmt.Printf("  total:%v\n", timesn)
	for k, v := range statistics {
		fmt.Printf("  k:%v v:%v\n", k, v)
	}
}

func req(url string) ([]byte, error) {
	response, err := http.Get(url)
	if err != nil {
		return []byte{}, err
	}
	defer response.Body.Close()
	return ioutil.ReadAll(response.Body)
}
