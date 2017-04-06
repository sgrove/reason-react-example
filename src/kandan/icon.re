module Icon = {
  include ReactRe.Component;
  let name = "Icon";
  type props = {name: string};
  let render {props} => {
    let scale = props.name == "loading" ? "" : "non-scaling-stroke";
    switch (Js.Null_undefined.to_opt (Paths.getIconPile Paths.iconPiles props.name)) {
    | None => ReactRe.nullElement
    | Some iconPile =>
      <i className=("icon icon-" ^ props.name)>
        <svg className="iconpile" viewBox="0 0 24 24">
          (
            ReactRe.arrayToElement (
              Array.mapi
                (
                  fun index pathName =>
                    <path
                      className=pathName
                      vectorEffect=scale
                      key=(string_of_int index)
                      d=(
                          switch (Js.Null_undefined.to_opt (Paths.getPath Paths.iconPaths pathName)) {
                          | None => ""
                          | Some path => path
                          }
                        )
                    />
                )
                iconPile
            )
          )
        </svg>
      </i>
    }
  };
};

include ReactRe.CreateComponent Icon;

let createElement ::name => wrapProps {name: name};
