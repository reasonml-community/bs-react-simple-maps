[@bs.module "react-simple-maps"]
external zoomableGroupClass : ReasonReact.reactClass = "ZoomableGroup";

type center = (int, int);

[@bs.deriving abstract]
type jsProps = {
  zoom: int,
  center,
  disablePanning: bool,
  style: ReactDOMRe.Style.t,
};

let make =
    (
      ~zoom: int=1,
      ~center: center=(0, 0),
      ~disablePanning: bool=false,
      ~style: ReactDOMRe.Style.t=ReactDOMRe.Style.make(),
      ~onMoveStart: option(center => unit)=?,
      ~onMoveEnd: option(center => unit)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=zoomableGroupClass,
    ~props=
      Js.Obj.assign(
        Obj.magic(jsProps(~zoom, ~center, ~disablePanning, ~style)),
        {
          "onMoveStart": Js.Null_undefined.fromOption(onMoveStart),
          "onMoveEnd": Js.Null_undefined.fromOption(onMoveEnd),
        },
      ),
    children,
  );
