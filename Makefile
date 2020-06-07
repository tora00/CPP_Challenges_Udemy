.PHONY: clean All

All:
	@echo "----------Building project:[ Section11Challenge - Debug ]----------"
	@cd "Section11Challenge" && "$(MAKE)" -f  "Section11Challenge.mk"
clean:
	@echo "----------Cleaning project:[ Section11Challenge - Debug ]----------"
	@cd "Section11Challenge" && "$(MAKE)" -f  "Section11Challenge.mk" clean
