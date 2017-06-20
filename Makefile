CODE_DIR=source
.PHONY: run
run:
	$(MAKE) -C $(CODE_DIR) && cp source/run ./

clean:
	rm run && $(MAKE) clean -C $(CODE_DIR)
