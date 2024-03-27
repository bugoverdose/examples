package example.bugoverdose.swagger.presentation;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import example.bugoverdose.swagger.auth.AuthUserId;

@RestController
@RequestMapping("/api/examples")
public class ExampleController implements SwaggerExampleController {

    @GetMapping("/{exampleId}")
    public ResponseEntity<Void> getExample(@AuthUserId Long resolvedArgument,
                                           @PathVariable Long exampleId,
                                           @RequestParam Boolean isExample) {
        // 생략
        return ResponseEntity.ok().build();
    }
}
