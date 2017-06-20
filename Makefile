CODE_DIR=src
.PHONY: run
run:
	$(MAKE) -C $(CODE_DIR) && cp src/run ./

clean:
	rm run && $(MAKE) clean -C $(CODE_DIR)
