package example.bugoverdose.swagger.presentation;

import org.springframework.http.ResponseEntity;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import springfox.documentation.annotations.ApiIgnore;

@Api(tags = {"예시 API"})
public interface SwaggerExampleController {

    @ApiOperation(value = "예시를 조회한다")
    ResponseEntity<Void> getExample(@ApiIgnore Long resolvedArgument,
                                    Long exampleId,
                                    Boolean isExample);
}
